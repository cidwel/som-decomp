.setcpu "65816"
.segment "CODE"
.org $B544
map_control_0fb544:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
