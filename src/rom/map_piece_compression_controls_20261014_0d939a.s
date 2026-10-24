.setcpu "65816"
.segment "CODE"
.org $939A
map_control_0d939a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
