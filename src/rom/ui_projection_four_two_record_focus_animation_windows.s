.setcpu "65816"
.segment "RODATA"
; Native consumer data at $C2B8B6; no graphics payload.
ui_focus_animation_0:
.byte $F8, $00 ; signed screen offsets
.word $7F8F ; native tile/attribute word
.byte $F8, $F8 ; signed screen offsets
.word $3F8F ; native tile/attribute word
ui_focus_animation_1:
.byte $F9, $F8 ; signed screen offsets
.word $3F8F ; native tile/attribute word
.byte $F9, $00 ; signed screen offsets
.word $7F8F ; native tile/attribute word
ui_focus_animation_2:
.byte $F9, $F8 ; signed screen offsets
.word $BF8F ; native tile/attribute word
.byte $F9, $00 ; signed screen offsets
.word $FF8F ; native tile/attribute word
ui_focus_animation_3:
.byte $F8, $F8 ; signed screen offsets
.word $BF8F ; native tile/attribute word
.byte $F8, $00 ; signed screen offsets
.word $FF8F ; native tile/attribute word
