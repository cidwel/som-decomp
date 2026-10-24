.setcpu "65816"
.segment "CODE"
.org $070B
map_control_0f070b:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
