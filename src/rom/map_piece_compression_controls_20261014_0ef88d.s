.setcpu "65816"
.segment "CODE"
.org $F88D
map_control_0ef88d:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
