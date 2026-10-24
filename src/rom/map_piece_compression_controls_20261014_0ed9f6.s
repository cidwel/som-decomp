.setcpu "65816"
.segment "CODE"
.org $D9F6
map_control_0ed9f6:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E2 ; previous-row copy count
