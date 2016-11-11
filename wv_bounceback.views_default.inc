<?php
/**
 * @file
 * wv_bounceback.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function wv_bounceback_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'wv_bounceback';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Bounceback';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Bounceback';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'wv_bounceback_display' => 'wv_bounceback_display',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/childs/%/bounceback';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Bounceback';
  $handler->display->display_options['menu']['name'] = 'devel';
  $translatables['wv_bounceback'] = array(
    t('Master'),
    t('Bounceback'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Page'),
  );
  $export['wv_bounceback'] = $view;

  $view = new view();
  $view->name = 'wv_bounceback_summary';
  $view->description = 'Cart line item summary displayed during checkout.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'World Vision Bounceback summary';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Shopping cart';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = TRUE;
  /* Relationship: Commerce Line item: Referenced products */
  $handler->display->display_options['relationships']['commerce_product_product_id']['id'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['relationships']['commerce_product_product_id']['field'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['label'] = 'Referenced Bounceback Product';
  $handler->display->display_options['relationships']['commerce_product_product_id']['required'] = TRUE;
  /* Relationship: Field: Referenced products */
  $handler->display->display_options['relationships']['field_child_reference_product_id']['id'] = 'field_child_reference_product_id';
  $handler->display->display_options['relationships']['field_child_reference_product_id']['table'] = 'field_data_field_child_reference';
  $handler->display->display_options['relationships']['field_child_reference_product_id']['field'] = 'field_child_reference_product_id';
  $handler->display->display_options['relationships']['field_child_reference_product_id']['relationship'] = 'commerce_product_product_id';
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['label'] = 'User Profile';
  /* Field: Commerce Product: Imagen Portada FrontEnd */
  $handler->display->display_options['fields']['field_imagen_portada_front_end_']['id'] = 'field_imagen_portada_front_end_';
  $handler->display->display_options['fields']['field_imagen_portada_front_end_']['table'] = 'field_data_field_imagen_portada_front_end_';
  $handler->display->display_options['fields']['field_imagen_portada_front_end_']['field'] = 'field_imagen_portada_front_end_';
  $handler->display->display_options['fields']['field_imagen_portada_front_end_']['relationship'] = 'commerce_product_product_id';
  $handler->display->display_options['fields']['field_imagen_portada_front_end_']['label'] = '';
  $handler->display->display_options['fields']['field_imagen_portada_front_end_']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imagen_portada_front_end_']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_imagen_portada_front_end_']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_imagen_portada_front_end_']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Commerce Product: Imagen Interior (Front-End) */
  $handler->display->display_options['fields']['field_imagen_interior_front_end_']['id'] = 'field_imagen_interior_front_end_';
  $handler->display->display_options['fields']['field_imagen_interior_front_end_']['table'] = 'field_data_field_imagen_interior_front_end_';
  $handler->display->display_options['fields']['field_imagen_interior_front_end_']['field'] = 'field_imagen_interior_front_end_';
  $handler->display->display_options['fields']['field_imagen_interior_front_end_']['relationship'] = 'commerce_product_product_id';
  $handler->display->display_options['fields']['field_imagen_interior_front_end_']['label'] = '';
  $handler->display->display_options['fields']['field_imagen_interior_front_end_']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imagen_interior_front_end_']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_imagen_interior_front_end_']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_imagen_interior_front_end_']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Commerce Product: Imagen Trasera (Front-End) */
  $handler->display->display_options['fields']['field_imagen_trasera_front_end_']['id'] = 'field_imagen_trasera_front_end_';
  $handler->display->display_options['fields']['field_imagen_trasera_front_end_']['table'] = 'field_data_field_imagen_trasera_front_end_';
  $handler->display->display_options['fields']['field_imagen_trasera_front_end_']['field'] = 'field_imagen_trasera_front_end_';
  $handler->display->display_options['fields']['field_imagen_trasera_front_end_']['relationship'] = 'commerce_product_product_id';
  $handler->display->display_options['fields']['field_imagen_trasera_front_end_']['label'] = '';
  $handler->display->display_options['fields']['field_imagen_trasera_front_end_']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imagen_trasera_front_end_']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_imagen_trasera_front_end_']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_imagen_trasera_front_end_']['settings'] = array(
    'file_view_mode' => 'full',
  );
  /* Field: Commerce Line item: Bounceback Text */
  $handler->display->display_options['fields']['field_wv_bounceback_text']['id'] = 'field_wv_bounceback_text';
  $handler->display->display_options['fields']['field_wv_bounceback_text']['table'] = 'field_data_field_wv_bounceback_text';
  $handler->display->display_options['fields']['field_wv_bounceback_text']['field'] = 'field_wv_bounceback_text';
  $handler->display->display_options['fields']['field_wv_bounceback_text']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['field_wv_bounceback_text']['label'] = '';
  $handler->display->display_options['fields']['field_wv_bounceback_text']['alter']['text'] = '[field_wv_bounceback_text-value]';
  $handler->display->display_options['fields']['field_wv_bounceback_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wv_bounceback_text']['type'] = 'list_default';
  /* Field: Field: Apellidos */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_child_reference_product_id';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['relationship'] = 'field_child_reference_product_id';
  $handler->display->display_options['fields']['sku']['label'] = '';
  $handler->display->display_options['fields']['sku']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sku']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Field: Field: Nombre */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_child_reference_product_id';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Para';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'De';
  /* Sort criterion: Commerce Line Item: Line item ID */
  $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['relationship'] = 'commerce_line_items_line_item_id';
  /* Contextual filter: Commerce Order: Order ID */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Commerce Line Item: Line item is of a product line item type */
  $handler->display->display_options['filters']['product_line_item_type']['id'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['product_line_item_type']['field'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['product_line_item_type']['value'] = '1';
  $handler->display->display_options['filters']['product_line_item_type']['group'] = 0;
  $translatables['wv_bounceback_summary'] = array(
    t('Defaults'),
    t('Shopping cart'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Line items referenced by commerce_line_items'),
    t('Referenced Bounceback Product'),
    t('Products referenced by field_child_reference'),
    t('Order owner'),
    t('User Profile'),
    t('[field_wv_bounceback_text-value]'),
    t('Para'),
    t('De'),
    t('All'),
  );
  $export['wv_bounceback_summary'] = $view;

  return $export;
}
