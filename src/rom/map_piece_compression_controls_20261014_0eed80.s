.setcpu "65816"
.segment "CODE"
.org $ED80
map_control_0eed80:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
