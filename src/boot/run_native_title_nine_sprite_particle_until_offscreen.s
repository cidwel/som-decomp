; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-particle-lifetime.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_eight_byte_record = $B1A9
append_pending_record = $B258
current_task_parent_id = $ACD0
draw_native_random_byte_below_low_byte_limit = $C288
initialize_nine_native_title_particle_sprites_and_random_velocity = $9808
integrate_native_title_particle_signed_fractional_positions = $9875
receive_with_supplied_delay = $ABE7
release_nine_native_title_particle_sprite_records = $97EF
select_native_task_stack_page_as_direct_page = $AD41

.segment "CODE"
.org $98AF
run_native_title_nine_sprite_particle_until_offscreen:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    jsr select_native_task_stack_page_as_direct_page
    .a16
    lda #$0000
    jsr draw_native_random_byte_below_low_byte_limit
    tax
    jsr receive_with_supplied_delay
    jsr initialize_nine_native_title_particle_sprites_and_random_velocity
    stz $1E
run_native_title_nine_sprite_particle_until_offscreen_98ce:
    jsr integrate_native_title_particle_signed_fractional_positions
    .i16
    ldx #$0002
    jsr receive_with_supplied_delay
    lda $1E
    inc
    sta $1E
    .a16
    and #$0003
    bne run_native_title_nine_sprite_particle_until_offscreen_98f0
    sep #$20
    lda $01
    inc
    .a8
    cmp #$0A
    bcc run_native_title_nine_sprite_particle_until_offscreen_98ec
    .a8
    lda #$00
run_native_title_nine_sprite_particle_until_offscreen_98ec:
    sta $01
    rep #$20
run_native_title_nine_sprite_particle_until_offscreen_98f0:
    lda $0A
    clc
    .a16
    adc #$0028
    .a16
    and #$8000
    beq run_native_title_nine_sprite_particle_until_offscreen_98ce
    jsr release_nine_native_title_particle_sprite_records
    jsr current_task_parent_id
    pha
    jsr allocate_eight_byte_record
    pla
    jsr append_pending_record
    plb
    plp
    pld
    rtl
