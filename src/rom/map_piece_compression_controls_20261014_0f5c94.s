.setcpu "65816"
.segment "CODE"
.org $5C94
map_control_0f5c94:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
