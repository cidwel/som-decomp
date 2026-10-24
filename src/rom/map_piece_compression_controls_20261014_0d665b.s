.setcpu "65816"
.segment "CODE"
.org $665B
map_control_0d665b:
    .byte $E1 ; previous-row copy count
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
    .byte $E1 ; previous-row copy count
