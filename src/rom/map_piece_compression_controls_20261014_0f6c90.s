.setcpu "65816"
.segment "CODE"
.org $6C90
map_control_0f6c90:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
