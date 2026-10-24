.setcpu "65816"
.segment "CODE"
.org $039B
map_control_0f039b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
