.setcpu "65816"
.segment "CODE"
.org $AE30
map_control_0eae30:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
