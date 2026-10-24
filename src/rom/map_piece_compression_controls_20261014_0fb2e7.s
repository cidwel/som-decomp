.setcpu "65816"
.segment "CODE"
.org $B2E7
map_control_0fb2e7:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
