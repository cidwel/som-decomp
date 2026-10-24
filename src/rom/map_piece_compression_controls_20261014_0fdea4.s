.setcpu "65816"
.segment "CODE"
.org $DEA4
map_control_0fdea4:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
