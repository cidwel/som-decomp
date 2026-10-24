.setcpu "65816"
.segment "CODE"
.org $AD17
map_control_0ead17:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
