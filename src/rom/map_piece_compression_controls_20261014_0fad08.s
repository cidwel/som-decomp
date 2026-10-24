.setcpu "65816"
.segment "CODE"
.org $AD08
map_control_0fad08:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
