.setcpu "65816"
.segment "CODE"
.org $7ED0
map_control_0d7ed0:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
