.setcpu "65816"
.segment "CODE"
.org $54F9
map_control_0d54f9:
    .byte $E1 ; previous-row copy count
    .byte $CA ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E4 ; previous-row copy count
