# Hollow Pulse

# GDD - GENERAL OVERVIEW: "THE BOOK OF MUTATIONS"
**Engine / Style:** C + Raylib, Low-Poly 3D Graphics.
**Aesthetic / Tonal References:** *Soul Eater* (body deformation, fluid madness), *Neon Genesis Evangelion*
(mystical crypticism, anguishing technology, ancestral species), *Nier automata* (Technology and robots).

---

## 1. WORLD
The game world is a universe suspended between ancestral mysticism and the dawn of computer technology.
Human civilization is militarized, expansionist, and deeply dogmatic. Magic in this world is called the 
**Alchemy of Change**: it is not a divine gift, but the manipulation of physical laws.
However, the world is **subtly aware of being a computer program**. As humanity begins to invent its 
first computers, scientists and alchemists uneasily notice that their technological systems operate 
according to the exact same principles as ancient magic. Alchemy is nothing more than the ability to read 
and rewrite the binary code of reality. The main setting is a mysterious island, scattered with military 
ruins and traces of an ancient civilization, regarded as hostile by humanity.

## 2. THEME
The central theme of the work is the **acceptance of change**. And the spontaneity of nature opposed to the man.

## 3. PROTAGONIST — VANE GAUGE
**Background:**
Vane is a decorated **Executioner**, an elite military alchemist of the Human Empire, raised in the **Foundry**,
where orphaned children are shaped into living weapons. He earned distinction not through zeal, but 
through his complete lack of hesitation: he could impose mutation, erase anomalies, and kill Beast-Men 
without flinching. Now reassigned to the Island, he has been ordered to “purify” its wild ancestral zones 
and force reality back into human control.

**Aspect:**
Tall, lean, and pale, Vane looks less like a hero than a weapon worn smooth by use. His left forearm 
is marked by geometric **compiler scars**, burns left by years of channeling high-octagram mutations 
through his own body. He wears a patched military coat, carries a debugging staff and a the famous page 255 
of the **Book of Mutations**, and moves with an unnerving, mechanical precision.

**Personality:**
Vane’s defining trait is **sincerity**: he does not glorify war, but neither does he lie about what it is. 
Yet beneath that certainty lies a quiet fracture — a growing fascination with the beauty of the very 
things he has been ordered to erase. He is a character in profound crisis, because he senses that what they 
are making him do is actually wrong.

## 4. CONFLICT
*   **Apparent Conflict:** A war of extermination for survival between Humanity and the Beast-Men (The first race).
*   **Real Conflict:** Humanity is actually the “unworthy” and usurping species. The Beast-Men are the
ancestral race that gave life to the Earth and created the discipline of Alchemy. Humans use a corrupted
and limited form of magic, based on the forced imposition of form, which collapses immediately afterward.
The true conflict is between man’s arrogant limitation and the natural flow of the universe preserved by the ancients.

## 5. SYMBOLS (The Power System)
The central object and symbol of the game is the **Book of Mutations**, a text of exactly 256 pages. Each 
page describes a transformation and is represented by an *Octagram* (8 bits).

Each transformation in the Book is described exclusively through three phrases/phases: **Before**, **Now**, and **After**.
These three phases are mathematically interlocked within the octagram through shared bits, proving that change 
passes through states without ever breaking them apart.
Therefore, for a human to comprehend a mutation means knowing how to apply this framework to a specific situation, 
working by association. By recognizing the Before, Now, and After of a natural phenomenon, the human essentially 
"reinterprets the past," bringing reality under their control. For instance, to freeze water into ice, one must 
anticipate the natural movement of the water and intervene to make it mutate differently: the alchemist recognizes 
the Before, Now, and After of the water—which shifts like a harmonic wave (naturally associated with an Octagram X) 
and then replaces this sequence with another Octagram from the Book, forcing reality to execute a different code.
The alchemy of change doesent produce events: recognize mutations in becoming and suggest to reality to take a slight turn.

---

## APPENDIX: Logical Structure of the Octagram

The system is based on an array of 8 bits divided into three interconnected sections (Trigram, Quadrigram, Trigram). The connection is created by the sharing of the 3rd and 6th bits.

```text
Base Structure:
[b1, b2, b3, b4, b5, b6, b7, b8] (b stands for bit)

The three Phases:
Left   = {b1, b2, b3}      -> "BEFORE" (7 Elements)
Center = {b3, b4, b5, b6}  -> "NOW" / The Mutation (15 Elements)
Right  = {b6, b7, b8}      -> "AFTER" (7 Elements)
```

### Example in Binary Code (10011100):

```text
Octagram: 1001 1100

Left   (Before) = 100
Center (Now)    = 0111
Right  (After)  = 100
```
