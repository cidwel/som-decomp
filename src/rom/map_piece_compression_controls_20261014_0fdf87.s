.setcpu "65816"
.segment "CODE"
.org $DF87
map_control_0fdf87:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C9 ; same-value copy count/distance
