.setcpu "65816"
.segment "CODE"
.org $39BF
map_control_0e39bf:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
