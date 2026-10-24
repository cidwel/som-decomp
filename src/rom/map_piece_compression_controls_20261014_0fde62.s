.setcpu "65816"
.segment "CODE"
.org $DE62
map_control_0fde62:
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
