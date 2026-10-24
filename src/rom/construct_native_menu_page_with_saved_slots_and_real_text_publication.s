; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-menu-pages.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_sprite_and_tile_workspaces = $2781
clear_title_menu_instruction_strip_when_requested = $2985
execute_native_menu_page_record_commands = $2443
expand_native_menu_fixed_ornament_records = $23CF
render_native_menu_description_with_alternating_rows = $2293
render_native_menu_heading_until_text_command = $2227
render_native_shop_item_tile_frame = $C76170
routine_c75979 = $C75979
upload_complete_native_menu_tile_workspace = $25AD

.segment "CODE"
.org $21DB
construct_native_menu_page_with_saved_slots_and_real_text_publication:
    stz a:$A198
    jsr render_native_menu_heading_until_text_command
    lda a:$A202
    .a8
    cmp #$03
    bne construct_native_menu_page_with_saved_slots_and_real_text_publication_c021e8
construct_native_menu_page_with_saved_slots_and_real_text_publication_c021e8:
    jsr render_native_menu_description_with_alternating_rows
    .a8
    lda #$02
    bit a:$A212
    beq construct_native_menu_page_with_saved_slots_and_real_text_publication_c021f9
    trb a:$A212
    jsl f:routine_c75979
construct_native_menu_page_with_saved_slots_and_real_text_publication_c021f9:
    jsr clear_native_menu_sprite_and_tile_workspaces
    lda a:$A202
    .a8
    cmp #$05
    bne construct_native_menu_page_with_saved_slots_and_real_text_publication_c02207
    jsl f:render_native_shop_item_tile_frame
construct_native_menu_page_with_saved_slots_and_real_text_publication_c02207:
    .i16
    ldx #$2050
    stx a:$A1C7
    jsr expand_native_menu_fixed_ornament_records
    lda a:$A202
    .a8
    cmp #$07
    bne construct_native_menu_page_with_saved_slots_and_real_text_publication_c0221d
    .i16
    ldx #$2184
    stx a:$A1C7
construct_native_menu_page_with_saved_slots_and_real_text_publication_c0221d:
    jsr execute_native_menu_page_record_commands
    jsr clear_title_menu_instruction_strip_when_requested
    jsr upload_complete_native_menu_tile_workspace
    rts
