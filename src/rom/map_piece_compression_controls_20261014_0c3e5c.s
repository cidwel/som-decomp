.setcpu "65816"
.segment "CODE"
.org $3E5C
map_control_0c3e5c:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
