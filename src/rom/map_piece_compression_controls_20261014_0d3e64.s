.setcpu "65816"
.segment "CODE"
.org $3E64
map_control_0d3e64:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
