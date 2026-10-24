.setcpu "65816"
.segment "CODE"
.org $105A
map_control_0f105a:
    .byte $EE ; backreference distance high bits
    .byte $99 ; distance low bit/count
