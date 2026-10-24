; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

create_ordinary_map_object = $DE3B
routine_02c757 = $2C757
test_map_object_inside_load_window = $DF85

.segment "CODE"
.org $DDE3
test_map_object_creation_eligibility_and_dispatch:
    sep #$20
    lda a:$C807,Y
    .a8
    and #$40
    beq test_map_object_creation_eligibility_and_dispatch_c0ddf4
    jsl f:routine_02c757
    bcs test_map_object_creation_eligibility_and_dispatch_c0de00
    bcc test_map_object_creation_eligibility_and_dispatch_c0ddff
test_map_object_creation_eligibility_and_dispatch_c0ddf4:
    jsl f:routine_02c757
    bcc test_map_object_creation_eligibility_and_dispatch_c0ddff
    jsr test_map_object_inside_load_window
    bcs test_map_object_creation_eligibility_and_dispatch_c0de00
test_map_object_creation_eligibility_and_dispatch_c0ddff:
    rts
test_map_object_creation_eligibility_and_dispatch_c0de00:
    sep #$20
    lda a:$C80D,Y
    .a8
    cmp #$57
    bcc create_ordinary_map_object
    .a8
    cmp #$80
    bcs create_ordinary_map_object
