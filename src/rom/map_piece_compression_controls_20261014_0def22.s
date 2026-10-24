.setcpu "65816"
.segment "CODE"
.org $EF22
map_control_0def22:
    .byte $F1 ; progressive-copy count
    .byte $C9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
