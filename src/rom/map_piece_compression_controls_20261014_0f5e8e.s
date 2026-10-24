.setcpu "65816"
.segment "CODE"
.org $5E8E
map_control_0f5e8e:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
