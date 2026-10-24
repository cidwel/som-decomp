.setcpu "65816"
.segment "CODE"
.org $847B
map_control_0e847b:
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
