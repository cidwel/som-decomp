; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-purchase.md.
.setcpu "65816"
.smart
.a8
.i16

confirm_native_shop_transaction_with_real_dialogue_and_controller = $7E30
deduct_native_shop_price_from_persistent_money = $7D0D
display_native_shop_message_wait_release_and_new_button_then_refresh = $7E95
insert_native_purchased_shop_item_and_consume_inventory_result_flag = $7D83
play_native_purchase_sound_and_publish_numeric_window_twice = $7B00
resolve_native_shop_item_price_and_test_money_preserving_item = $7C7B
routine_c07b0c = $7B0C
select_native_shop_insufficient_money_notice = $7B0D
select_native_shop_inventory_capacity_notice = $7B12

.segment "CODE"
.org $7AD1
buy_native_selected_shop_item_after_confirmation_and_capacity_checks:
    jsr confirm_native_shop_transaction_with_real_dialogue_and_controller
    bne routine_c07b0c
    rep #$30
    lda a:$180A
    .a16
    and #$00FF
    clc
    adc a:$183C
    tax
    lda f:$D80000,X
    jsr resolve_native_shop_item_price_and_test_money_preserving_item
    .i16
    cpx #$0000
    bne select_native_shop_insufficient_money_notice
    jsr insert_native_purchased_shop_item_and_consume_inventory_result_flag
    bne select_native_shop_inventory_capacity_notice
    jsr deduct_native_shop_price_from_persistent_money
    jsr play_native_purchase_sound_and_publish_numeric_window_twice
    .i16
    ldx #$FE20
    jmp display_native_shop_message_wait_release_and_new_button_then_refresh
