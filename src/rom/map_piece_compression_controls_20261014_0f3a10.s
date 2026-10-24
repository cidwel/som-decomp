.setcpu "65816"
.segment "CODE"
.org $3A10
map_control_0f3a10:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
