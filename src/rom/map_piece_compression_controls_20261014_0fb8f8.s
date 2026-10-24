.setcpu "65816"
.segment "CODE"
.org $B8F8
map_control_0fb8f8:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
