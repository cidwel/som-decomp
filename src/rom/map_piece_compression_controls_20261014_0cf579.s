.setcpu "65816"
.segment "CODE"
.org $F579
map_control_0cf579:
    .byte $C7 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
