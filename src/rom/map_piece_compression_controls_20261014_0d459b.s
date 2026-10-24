.setcpu "65816"
.segment "CODE"
.org $459B
map_control_0d459b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
