.setcpu "65816"
.segment "CODE"
.org $9DCE
map_control_0d9dce:
    .byte $E8 ; backreference distance high bits
    .byte $48 ; distance low bit/count
