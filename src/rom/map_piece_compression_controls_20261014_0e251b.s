.setcpu "65816"
.segment "CODE"
.org $251B
map_control_0e251b:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $F4 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
