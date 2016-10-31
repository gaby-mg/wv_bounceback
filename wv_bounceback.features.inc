<?php
/**
 * @file
 * wv_bounceback.features.inc
 */

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
