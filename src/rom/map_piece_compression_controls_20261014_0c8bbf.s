.setcpu "65816"
.segment "CODE"
.org $8BBF
map_control_0c8bbf:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
