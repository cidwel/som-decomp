.setcpu "65816"
.segment "CODE"
.org $906A
map_control_0d906a:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
