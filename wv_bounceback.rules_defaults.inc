<?php
/**
 * @file
 * wv_bounceback.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function wv_bounceback_default_rules_configuration() {
  $items = array();
  $items['rules_wv_bounceback_checkout'] = entity_import('rules_config', '{ "rules_wv_bounceback_checkout" : {
      "LABEL" : "Bounceback Checkout",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "commerce_order", "commerce_rules_extra" ],
      "ON" : { "commerce_rules_extra_process_checkout_page" : [] },
      "IF" : [
        { "commerce_order_contains_product_type" : {
            "commerce_order" : [ "site:current-cart-order" ],
            "product_type" : { "value" : { "wv_bounceback" : "wv_bounceback" } },
            "operator" : "\\u003E=",
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "commerce_rules_extra_change_pane" : {
            "pane_id" : "cart_contents",
            "page_id" : "\\u003Csame\\u003E",
            "enabled" : "0"
          }
        },
        { "commerce_rules_extra_change_pane" : {
            "pane_id" : "customer_profile_wv_adtnl_info",
            "page_id" : "review",
            "enabled" : "1"
          }
        },
        { "commerce_rules_extra_change_pane" : {
            "pane_id" : "customer_profile_billing",
            "page_id" : "review",
            "enabled" : "1"
          }
        }
      ]
    }
  }');
  $items['rules_wv_bounceback_child'] = entity_import('rules_config', '{ "rules_wv_bounceback_child" : {
      "LABEL" : "Set Bounceback Child",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Cart" ],
      "REQUIRES" : [ "rules", "rules_url_argument", "commerce_cart" ],
      "ON" : { "commerce_cart_product_prepare" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "commerce-product" ], "type" : "commerce_product" } },
        { "data_is" : { "data" : [ "commerce-product:type" ], "value" : "wv_bounceback" } }
      ],
      "DO" : [
        { "rules_url_argument_rules_action_get_argument_from_url" : {
            "USING" : { "type" : "text", "argument_name" : "child" },
            "PROVIDE" : { "argument_from_url" : { "child_sku" : "Child SKU" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "sku",
              "value" : [ "child-sku" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "child" : "Bounceback Child" } }
          }
        },
        { "data_set" : {
            "data" : [ "commerce-product:field-child-reference" ],
            "value" : [ "child:0" ]
          }
        }
      ]
    }
  }');
  $items['rules_wv_bounceback_donation'] = entity_import('rules_config', '{ "rules_wv_bounceback_donation" : {
      "LABEL" : "Enable Donation form for Bounceback",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "commerce_order", "commerce_rules_extra" ],
      "ON" : { "commerce_rules_extra_process_checkout_pane" : [] },
      "IF" : [
        { "commerce_order_contains_product_type" : {
            "commerce_order" : [ "commerce_order" ],
            "product_type" : { "value" : { "wv_bounceback" : "wv_bounceback" } },
            "operator" : "\\u003E=",
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "commerce_rules_extra_change_pane" : {
            "pane_id" : "checkout_donate",
            "page_id" : "checkout",
            "enabled" : "1",
            "weight" : "10"
          }
        }
      ]
    }
  }');
  $items['rules_wv_bounceback_review_ecard'] = entity_import('rules_config', '{ "rules_wv_bounceback_review_ecard" : {
      "LABEL" : "Enable Review Your E-Card for Bounceback",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout", "World Vision" ],
      "REQUIRES" : [ "commerce_order", "commerce_rules_extra" ],
      "ON" : { "commerce_rules_extra_process_checkout_pane" : [] },
      "IF" : [
        { "commerce_order_contains_product_type" : {
            "commerce_order" : [ "commerce_order" ],
            "product_type" : { "value" : { "wv_bounceback" : "wv_bounceback" } },
            "operator" : "\\u003E=",
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "commerce_rules_extra_change_pane" : {
            "pane_id" : "review_your_ecard",
            "page_id" : "checkout",
            "enabled" : "1"
          }
        }
      ]
    }
  }');
  $items['worldvision_ecommerce_wv_bounceback_express_checkout'] = entity_import('rules_config', '{ "worldvision_ecommerce_wv_bounceback_express_checkout" : {
      "LABEL" : "Bounceback Express Checkout",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "rules", "commerce_cart" ],
      "ON" : { "commerce_cart_product_add" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "commerce-product:type" ],
            "op" : "IN",
            "value" : { "value" : { "wv_bounceback" : "wv_bounceback" } }
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "checkout\\/[commerce-order:order-id]" } } ]
    }
  }');
  return $items;
}
