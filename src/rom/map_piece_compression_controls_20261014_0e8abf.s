.setcpu "65816"
.segment "CODE"
.org $8ABF
map_control_0e8abf:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
