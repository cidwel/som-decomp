.setcpu "65816"
.segment "CODE"
.org $7B04
map_control_0f7b04:
    .byte $C2 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E4 ; previous-row copy count
