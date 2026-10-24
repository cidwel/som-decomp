.setcpu "65816"
.segment "CODE"
.org $6462
map_control_0f6462:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $C9 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
