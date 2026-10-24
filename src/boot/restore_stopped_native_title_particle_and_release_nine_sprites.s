; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-particle-stop.md.
.setcpu "65816"
.smart
.a8
.i16

release_nine_native_title_particle_sprite_records = $97EF
select_native_task_stack_page_as_direct_page = $AD41

.segment "CODE"
.org $990D
restore_stopped_native_title_particle_and_release_nine_sprites:
    phd
    php
    rep #$30
    sep #$20
    jsr select_native_task_stack_page_as_direct_page
    jsr release_nine_native_title_particle_sprite_records
    plp
    pld
    rtl
