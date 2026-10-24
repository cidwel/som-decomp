.setcpu "65816"
.segment "CODE"
.org $FB77
map_control_0cfb77:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
