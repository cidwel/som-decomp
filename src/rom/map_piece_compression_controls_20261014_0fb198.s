.setcpu "65816"
.segment "CODE"
.org $B198
map_control_0fb198:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
