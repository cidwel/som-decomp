; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

divide_native_status_bar_and_publish_selected_actor_vram = $67E6
scale_native_status_bar_fields_with_shift_or_mode7_product = $684D

.segment "CODE"
.org $67D8
select_native_status_bar_conversion_for_first_ten_fields:
    lda a:$A175
    .a8
    cmp #$0A
    bcs select_native_status_bar_conversion_for_first_ten_fields_c767e5
    jsr scale_native_status_bar_fields_with_shift_or_mode7_product
    jsr divide_native_status_bar_and_publish_selected_actor_vram
select_native_status_bar_conversion_for_first_ten_fields_c767e5:
    rts
