.setcpu "65816"
.segment "CODE"
.org $34D7
map_control_0f34d7:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
