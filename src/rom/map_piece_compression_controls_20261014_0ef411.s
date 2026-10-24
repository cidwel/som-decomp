.setcpu "65816"
.segment "CODE"
.org $F411
map_control_0ef411:
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $32 ; distance low bit/count
