.setcpu "65816"
.segment "CODE"
.org $DC12
map_control_0edc12:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $9D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
