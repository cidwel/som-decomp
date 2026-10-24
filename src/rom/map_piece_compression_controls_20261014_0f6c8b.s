.setcpu "65816"
.segment "CODE"
.org $6C8B
map_control_0f6c8b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
