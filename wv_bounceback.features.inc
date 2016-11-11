<?php
/**
 * @file
 * wv_bounceback.features.inc
 */

/**
 * Implements hook_commerce_line_item_default_types().
 */
function wv_bounceback_commerce_line_item_default_types() {
  $items = array(
    'wv_bounceback' => array(
      'name' => 'Bounceback',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_product_default_types().
 */
function wv_bounceback_commerce_product_default_types() {
  $items = array(
    'wv_bounceback' => array(
      'type' => 'wv_bounceback',
      'name' => 'Bounceback',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function wv_bounceback_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "commerce_autosku" && $api == "autosku_pattern") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function wv_bounceback_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function wv_bounceback_node_info() {
  $items = array(
    'wv_bounceback_display' => array(
      'name' => t('Bounceback Display'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
