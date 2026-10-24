.setcpu "65816"
.segment "CODE"
.org $AEFE
map_control_0faefe:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
