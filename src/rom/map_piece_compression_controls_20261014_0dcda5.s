.setcpu "65816"
.segment "CODE"
.org $CDA5
map_control_0dcda5:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
