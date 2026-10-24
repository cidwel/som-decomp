.setcpu "65816"
.segment "CODE"
.org $7B01
map_control_0f7b01:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
