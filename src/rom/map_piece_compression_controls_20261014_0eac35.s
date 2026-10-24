.setcpu "65816"
.segment "CODE"
.org $AC35
map_control_0eac35:
    .byte $CD ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
