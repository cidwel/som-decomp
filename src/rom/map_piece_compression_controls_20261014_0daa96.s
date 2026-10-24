.setcpu "65816"
.segment "CODE"
.org $AA96
map_control_0daa96:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $C3 ; same-value copy count/distance
