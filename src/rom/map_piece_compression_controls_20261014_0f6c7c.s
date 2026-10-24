.setcpu "65816"
.segment "CODE"
.org $6C7C
map_control_0f6c7c:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
